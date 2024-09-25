package main.java.GameEngine.Utils;

import java.lang.reflect.Array;
import java.util.Vector;

public class SparseSet<T>
{
    // Will contain the components.
    private Vector<T> dense;
    // Will contain the index of the component in the dense vector. Use a paging system.
    private Vector<Vector<Integer>> sparse_pages;
    private Vector<Integer> denseToEntity;
    private final int PAGE_SIZE = 1000;

    public SparseSet()
    {
        dense = new Vector<>(100);
        denseToEntity = new Vector<>(100);
        sparse_pages = new Vector<>();
    }

    /*
     * sparse[id] = index of the object in the dense set.
     *
     * Example:
     * - set(3, "Hello");
     * sparse = [-1, -1, -1, 0]
     * dense = ["Hello"]
     *
     * - set(0, "World");
     * sparse = [1, -1, -1, 0]
     * dense = ["Hello", "World"]
     *
     * - set(2, "!");
     * sparse = [1, -1, 2, 0]
     * dense = ["Hello", "World", "!"]
     */
    public void set(int id, T object)
    {
        int page_nb = id / PAGE_SIZE;
        int sparseIndex = id % PAGE_SIZE;

        if (page_nb >= sparse_pages.size())
        {
            sparse_pages.setSize(page_nb + 1);
            Vector<Integer> page = sparse_pages.get(page_nb);
            if (page == null)
            {
                page = new Vector<>(PAGE_SIZE);
                for (int i = 0; i < PAGE_SIZE; i++)
                {
                    page.add(-1);
                }
                sparse_pages.setElementAt(page, page_nb);
            }
        }

        sparse_pages.get(page_nb).set(sparseIndex, dense.size());
        denseToEntity.add(dense.size(), id);
        dense.addElement(object);
    }

    /*
     * Swap back deletion.
     *
     * Example:
     * - set(3, "Hello");
     * - set(0, "World");
     * - set(2, "!");
     * sparse = [1, -1, 2, 0]
     * dense = ["Hello", "World", "!"]
     *
     * - delete(3);
     * sparse = [1, -1, 0, -1]
     * dense = ["!", "World"]
     */
    public void delete(int id)
    {
        int page_nb = id / PAGE_SIZE;
        int sparseIndex = id % PAGE_SIZE;

        if (page_nb < sparse_pages.size())
        {
            int denseIndex = sparse_pages.get(page_nb).get(sparseIndex);
            sparse_pages.get(page_nb).set(sparseIndex, -1);

            if (denseIndex != -1)
            {
                dense.set(denseIndex, dense.lastElement());
                dense.remove(dense.size() - 1);

                int denseLastId = denseToEntity.get(dense.size());
                denseToEntity.set(denseIndex, denseLastId);
                sparse_pages.get(denseLastId / PAGE_SIZE).set(denseLastId % PAGE_SIZE, denseIndex);
            }
        }
    }

    public T get(int id)
    {
        int page_nb = id / PAGE_SIZE;
        int sparseIndex = id % PAGE_SIZE;

        if (page_nb >= sparse_pages.size())
        {
            return null;
        }

        int denseIndex = sparse_pages.get(page_nb).get(sparseIndex);
        return denseIndex == -1 ? null : dense.get(denseIndex);
    }
}
