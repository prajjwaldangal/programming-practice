import java.util.*;

// min heap
public class HeapDefinition<ItemType extends Number & Comparable <? super ItemType>> {
       
    private List<ItemType> heap;
    private int size = 0;
    private int capacity = 10;

    HeapDefinition() {
        heap = new ArrayList<ItemType>(capacity);
    }

    HeapDefinition(int capacity) {
        heap = new ArrayList<ItemType>(capacity);
        this.capacity = capacity;
    }

    private int getLeftChildIndx (int parentIndx) {
        return 2 * parentIndx + 1;
    }

    private int getRightChildIndx (int parentIndx) {
        return 2 * parentIndx + 2;
    }

    private int getParentIndx (int childIndx) {
        return (childIndx - 1) / 2;
    }

    private void heapifyUp(int indx) {
        // int indx = size-1;
        int pIndx = getParentIndx(indx);
        if (heap.get(pIndx).compareTo(heap.get(indx)) < 0) {
            ItemType tmp = heap.get(pIndx);
            heap.set(pIndx, heap.get(indx));
            heap.set(indx, tmp);

        }
    }

    private void heapifyDown() {

    }

    private void ensureCapacity() {
        
        if (size == capacity) {
            List <ItemType> newHeap = new ArrayList<>(capacity*2);
            for (int i = 0; i < capacity; i++) {
                newHeap.set(i, heap.get(i));
            }
            heap = newHeap;
            capacity *= 2;
        }
    }

    public void print() {
        // System.out.
    }

    public void insert (ItemType item) {
        ensureCapacity();
        heap.set(size, item);
        size += 1;
        heapifyUp(size - 1);
    }

    public ItemType remove () {
        if (size == 0) throw new IllegalStateException();
        ItemType item = heap.get(0);
        heap.set(0, heap.get(size-1));
        size--;
        heapifyDown();
        return item;
    }

    public static void main(String[] args) {
        
    }
}