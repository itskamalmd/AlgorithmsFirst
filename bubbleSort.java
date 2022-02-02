public class bubbleSort {
    //i dont know the actual name of this algorithm 
    public static int[] bubbleSortNums (int[] nums) {
        for (int i = 0; i < nums.length; i++){
            for(int j= 0; j < i; j++){
                if (nums [i] < nums [j]){
                    int temp = nums[i];
                    nums[i] = nums[j]; 
                    nums[j] = temp;
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