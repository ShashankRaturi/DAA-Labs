public class Linear_search{

	public static void search(int[] arr, int key){
		int numOfComparisons = 0;
		boolean found = false;
		
		for(int i = 0; i < arr.length; ++i){
			++numOfComparisons;
			if(arr[i] == key){
				found = true;
				break;
			}
		}
		if(found){
			System.out.println("key found on " + numOfComparisons + " comparisons.");
		}else{
			System.out.println("key not found");
		}
		
	}	
	
    public static void main(String[] args){
		int[] arr1 = {2,7,0,65,3,88};
		search(arr1 , 33);
		 
    }
}
