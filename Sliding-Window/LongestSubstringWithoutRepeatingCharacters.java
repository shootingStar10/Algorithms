class LongestSubstringWithoutRepeatingCharacters {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0) {
                        return 0;
                }

                if(s.length() == 1) {
                        return 1;
                }

                Map<Character, Integer> charMap = new HashMap ();
                int ans = 0;
                int left = 0;
                int max = 0;

                for(int i = 0; i < s.length(); i++) {
                        if(charMap.containsKey (s.charAt (i)) && charMap.get (s.charAt (i)) >= left) {
                                left = charMap.get (s.charAt (i))+1;
                                ans = i - left;
                        }

                        charMap.put (s.charAt (i), i);
                        ans++;

                        if(max < ans) {
                                max = ans;
                        }
                }

                return max;
    }
}