import java.util.Arrays;
import java.util.Random;

public class QuickSortInJava {
  public static void main(String[] args) {
    int[] array = new int[args.length];
    //Creates a array and parses elements into it
    for (int i = 0; i < args.length; i++) {
      array[i] = Integer.parseInt(args[i]);
    }
    //starts the quicksort call
    quickSort(array);
    //print output
    System.out.println(Arrays.toString(array));
  }

  public static void quickSort(int[] array) {
    //calls the recursive function so that we can have a layer between the extra parameters
    quickSortBootstrap(array, 0, array.length - 1);
  }

  private static void quickSortBootstrap(int[] array, int start, int end) {
    //check for base case and return if found
    if(start >= end) {
      return;
    }
    //create a middling pivot and then also assign its value for easier comparison
    int pivotIndex = (start+end) / 2;
    int pivotValue = array[pivotIndex];
    //assign my pointers for ref
    int i = start;
    int j = end;
    // making sure that the start pointer is less than or equal to the end pointer
    while(i <= j) {
      //checking to see if the left pointer is less than the pivotValue
      while(array[i] < pivotValue) {
        i++;
      }
      //checking to see if j is greater than the pivot value
      while(array[j] > pivotValue) {
        j--;
      }
      //I was less than pivot and J was greater than pivotvalue and then we make sure that i is less than or equal to J. checks to see if i is less than j and if it is then it swaps their places
      //THIS IS WHEN ARRAY I IS CREATER THAN PIVOT AND WHEN J IS LESS THAN PIVOT
    
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
