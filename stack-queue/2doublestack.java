
/*
2.双栈队列
编写一个类,只能用两个栈结构实现队列,支持队列的基本操作(push，pop)。

给定一个操作序列ope及它的长度n，其中元素为正数代表push操作，为0代表pop操作，
保证操作序列合法且一定含pop操作，请返回pop的结果序列。
*/

import java.util.*;

public class TwoStack {
    public int[] twoStack(int[] ope, int n) {
        Stack a = new Stack();
        Stack b = new Stack();  
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i = 0 ; i < n ; i++){
            if(ope[i] == 0){
                while(a.empty() == false){
                    b.push(a.pop());
                }
                arr.add((int)b.pop());
                while(b.empty() == false){
                    a.push(b.pop());
                }
            }else{
                a.push(ope[i]);
            }
        }
        int[] result = new int[arr.size()];
        int index = 0;
        for (Integer inte : arr) {
            result[index] = (int) inte;
            index++;
        }
        return result;
    }
}
