/*
5.字符串移位
对于一个字符串，请设计一个算法，将字符串的长度为len的前缀平移到字符串的最后。
给定一个字符串A和它的长度，同时给定len，请返回平移后的字符串。
*/
import java.util.*;

public class Translation {
    public String stringTranslation(String A, int n, int len) {
        char[] c = A.toCharArray();
        StringBuffer sb = new StringBuffer();
        for(int i = len ; i < n ; i++){
            sb.append(c[i]);
        }
        for(int i = 0 ; i < len ; i++){
            sb.append(c[i]);
        }
        return sb.toString();
    }
}  
