/*
拼接最小字典序
对于一个给定的字符串数组，请找到一种拼接顺序，使所有小字符串拼接成的大字符串是所有可能的拼接中字典序最小的。
给定一个字符串数组strs，同时给定它的大小，请返回拼接成的串。
*/
import java.util.*;

public class Prior {
    public String findSmallest(String[] strs, int n) {
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if((strs[i] + strs[j]).compareTo(strs[j] + strs[i]) > 0){
                    String temp = strs[i];
                    strs[i] = strs[j];
                    strs[j] = temp;
                }
            }
        }
        StringBuffer sb = new StringBuffer();
        for(int i = 0 ; i < n ; i++)
            sb.append(strs[i]);
        return sb.toString();
    }
}  
