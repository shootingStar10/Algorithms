class Solution {
    public int oddEvenJumps(int[] A) {
                int count = 1;
                int[][] dp = new int[2][A.length];
                TreeMap<Integer, Integer> map = new TreeMap<> ();

                dp[0][A.length-1] = 1;
                dp[1][A.length-1] = 1;
                map.put (A[A.length-1], A.length-1);

                for(int i = A.length-2; i >= 0; i--) {
                        Integer nextGreater = map.ceilingKey (A[i]);
                        if(nextGreater != null) {
                                dp[0][i] = dp[1][map.get (nextGreater)];
                        }

                        Integer nextSmaller = map.floorKey (A[i]);
                        if(nextSmaller != null) {
                                dp[1][i] = dp[0][map.get (nextSmaller)];
                        }

                        map.put (A[i], i);

                        if(dp[0][i] == 1) {
                                count++;
                        }
                }

                return count;
        }
}