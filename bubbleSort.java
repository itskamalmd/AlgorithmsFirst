public class bubbleSort {
    // swap function 
    public static void swap(int[] arr,int index1,int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    //bubble sorting 
    public static int[] bubbleSortNums (int[] nums) {
        for (int i = 0; i < nums.length; i ++){
            for (int j = 0; j < nums.length-1; j++){
                if (nums[i] < nums[j]){
                    swap(nums,i,j);
                }
            }
        }
        return nums; 
    }
    public static void main(String [] args){
        int [] nums = {6,4,7,8,2,3};
        bubbleSortNums(nums);
        
        for(int i = 0; i < nums.length; i +=1){
            System.out.println(nums[i]);
        }
    } 
}