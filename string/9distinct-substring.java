/*
distinct-substring
对于一个字符串,请设计一个高效算法，找到字符串的最长无重复字符的子串长度。
给定一个字符串A及它的长度n，请返回它的最长无重复字符子串长度。
保证A中字符全部为小写英文字符，且长度小于等于500。
设字符串为s，当前位置i, dp[i-1]表示以i-1位置为结尾的最长无重复子串子串（以下简称为子串）的开始位置。并设置一个map,记录字符s[i]上一次出现的位置lastOcc。
*/
import java.util.*;

public class DistinctSubstring {
    public int longestSubstring(String A, int n) {
        if(n<=1) return n;
        int maxLen=0;
        Map<Character,Integer>map=new HashMap<>();
        char[] arr=A.toCharArray();
        map.put(arr[0],0);

        int pre=0;
        Integer lastOcr=null;
        for(int i=1;i<n;i++){
            lastOcr=map.get(arr[i]);
            if(lastOcr==null) lastOcr=-1;
            pre=Math.max(lastOcr+1,pre);
            maxLen=Math.max(i-pre+1,maxLen);
            map.put(arr[i],i);
        }
        return maxLen;
    }
}
