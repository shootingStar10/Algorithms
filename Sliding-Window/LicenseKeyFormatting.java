class Solution {
    public static String licenseKeyFormatting(String str, int k) {
                StringBuilder newStr = new StringBuilder ();

                for(int i = str.length ()-1; i >= 0;) {
                        int window = k;

                        while (window > 0 && i >= 0) {
                                Character c = str.charAt (i);

                                if(c.equals ('-')) {
                                        i--;
                                        continue;
                                }

                                newStr.append (c.toString ().toUpperCase ());

                                window--;
                                i--;
                        }

                        newStr.append ('-');
                }

                Character c = '-';
                while (newStr.length () > 0 && c.equals (newStr.charAt (newStr.length ()-1))) {
                        newStr.deleteCharAt (newStr.length ()-1);
                }

                return newStr.reverse ().toString ();
        }
}