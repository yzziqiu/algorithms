/*
合法括号序列判断
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
*/
import java.util.*;

public class Parenthesis {
    public boolean chkParenthesis(String A, int n) {
        char[] c = A.toCharArray();
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(c[i] != '(' && c[i] != ')')return false;
            else{
                if(c[i] == '(')count++;
                else count--;
            }
            if(count < 0)return false;
        }
        if(count == 0)return true;
        return false;
    }
}  
