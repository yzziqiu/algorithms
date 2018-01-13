

/* 2.对于两个字符串A和B，如果A和B中出现的字符种类相同且每种字符出现的次数相同，则A和B互为变形词，请设计一个高效算法，检查两给定串是否互为变形词。
在建立哈希表对应的数组时数组大小为256，
然后遍历祖父数组，对每一个字符，使用字符的ascii值计算得到的key作为哈希表数组的下标去哈希表中按照下标找对应的位置，
先遍历String1，每个元素+1，然后遍历String2，对每个元素-1，每次-1之后就检验是否<0如果小于0显然表示String2中该字符多余String1中的该字符，于是返回false即可。
当最后遍历完String2后再遍历哈希表，看每个位置是否为0，如果不为0则返回false
*/

import java.util.*;
public class Transform {
    public boolean chkTransform(String A, int lena, String B, int lenb) {
        if(A==null || B==null || A.length()!=B.length()){
            return false;
        }
        //将字符串转化为数组进行处理
        char[] char1=A.toCharArray();
        char[] char2=B.toCharArray();

        int[] array=new int[256];

        for(int i=0;i<char1.length;i++){
            array[char1[i]]++;
        }
        for(int i=0;i<char2.length;i++){
            array[char2[i]]--;
            if(array[char2[i]]<0){
                return false;
            }
        }
        return true;
    }
}
