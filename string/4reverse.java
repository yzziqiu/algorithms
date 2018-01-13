/*
句子逆序
题目：对于一个字符串，请设计一个算法，只在字符串的单词间做逆序调整，也就是说，字符串由一些由空格分隔的部分组成，你需要将这些部分逆序。
给定一个原字符串A和他的长度，请返回逆序后的字符串。
测试样例："dog loves pig",13返回："pig loves dog"
*/
import java.util.*;
//对输入的句子中的单词进行反转，单词内部保持不变
public class Reverse {
    public String reverseSentence(String A, int n) {
        //特殊输入
        if(A==null||A.length()<0) return null;

        //将字符串A转换为字符数组便于进行处理
        char[] array=A.toCharArray();

        //定义两个指针beginIndex,endIndex用来截取每个被空格分隔的单词
        int beginIndex=0;
        int endIndex=0;

        //先扫描字符串，找到单词，对每个单词内部进行反转
        while(beginIndex<=array.length&&endIndex<=array.length){
//如果遇到空格表示前面是一个单词，如果p2就已经到达最后即endIndex=length那么也表示前面是一个单词
            if(endIndex==array.length||array[endIndex]==' '){
                //对endIndex之前的字符串进行排序
                this.reverse(array,beginIndex,endIndex-1);
                endIndex++;
                beginIndex=endIndex;
            }else{
                endIndex++;
            }
        }

        //对整个句子进行反转
        this.reverse(array,0,array.length-1);

        //要求返回的是字符串，所以要将字符数组转变为字符串
        return String.valueOf(array);
    }

    //对字符串array从[p1~p2]的范围内的字符串进行反转
    public void reverse(char[] array,int p1,int p2){
        while(p1<p2){
            char temp=array[p2];
            array[p2--]=array[p1];
            array[p1++]=temp;
        }
    }
}
