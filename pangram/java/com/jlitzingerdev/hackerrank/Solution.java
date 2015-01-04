//Note: Pretty sure solutions submitted have to be in the default package
package com.jlitzingerdev.hackerrank;

import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;

class Solution {
    
    public static String isPangram(String candidate) {
        if (candidate.length() < 26) {
            return "not pangram";
        }

        char[] arr = candidate.toCharArray();
        Set<Character> s = new HashSet<Character>(26);
        for (char c : arr) {
            if (!Character.isSpaceChar(c)) {
                s.add(c);
            }
        }

        if (s.size() == 26) {
            return "pangram";
        }
        return "not pangram";
    }


    public static void main(String[] argv) {
        Scanner in = new Scanner(System.in);
        String candidate = in.nextLine();
        System.out.println(isPangram(candidate));
    }
}
