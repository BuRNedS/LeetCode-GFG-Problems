
class Solution {
    public static ArrayList<Integer> alternateSort(int[] arr) {
       ArrayList<Integer>ans=new ArrayList<>();
      Arrays.sort(arr);
      int i=0;
      int j=arr.length-1;
      
      while(i<=j){
          if(i==j){
            ans.add(arr[j]);
            break;
          }
          ans.add(arr[j]);
          j--;
          ans.add(arr[i]);
          i++;
      }
      return ans;
    }
}
