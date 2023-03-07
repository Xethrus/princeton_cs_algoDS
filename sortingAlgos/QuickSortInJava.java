import java.util.Arrays;
import java.util.Random;

public class QuickSortInJava {
  public static void main(String[] args) {
    int[] array = new int[args.length];
    for (int i = 0; i < args.length; i++) {
      array[i] = Integer.parseInt(args[i]);
    }
    quickSort(array);
    System.out.println(Arrays.toString(array));
  }

  public static void quickSort(int[] array) {
    quickSortBootstrap(array, 0, array.length - 1);
  }

  private static void quickSortBootstrap(int[] array, int start, int end) {
    if(start >= end) {
      return;
    }
    int pivotIndex = (start+end) / 2;
    int pivotValue = array[pivotIndex];
    int i = start;
    int j = end;
    while(i <= j) {
      while(array[i] < pivotValue) {
        i++;
      }
      while(array[j] > pivotValue) {
        j--;
      }
      if(i <= j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
      }
    }
    quickSortBootstrap(array, start, j);
    quickSortBootstrap(array, i, end);
  }
}
