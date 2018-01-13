/*
4.双栈排序
请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据结构中。
给定一个int[] numbers(C++中为vector<int>)，
其中第一个元素为栈顶，请返回排序后的栈。请注意这是一个栈，意味着排序过程中你只能访问到第一个元素。
*/
import java.util.Stack;
import java.util.ArrayList;

public class TwoStacks {
     public ArrayList<Integer> twoStacksSort(int[] numbers) {
            // write code here
         Stack<Integer> stack = new Stack<Integer>();
         Stack<Integer> stack1 = new Stack<Integer>();

         for(int i=0; i<numbers.length; i++){
             stack.push(numbers[i]);
         }

         while(!stack.isEmpty()){
             int tmp = stack.pop().intValue();
             while(!stack1.isEmpty() && stack1.peek() > tmp){
                 stack.push(stack1.pop());
             }
             stack1.push(tmp);
         }
         ArrayList<Integer> tmp1 = new ArrayList<Integer>();
         while(!stack1.isEmpty()){
             tmp1.add(stack1.pop());
         }
         return tmp1;
     }


     public Stack<Integer> twoStacksSort1(Stack<Integer> s) {
            // write code here
         Stack<Integer> stack = new Stack<Integer>();
         while(!s.isEmpty()){
             int tmp = s.pop();
             while(!stack.isEmpty() && stack.peek() > tmp){
                 s.push(stack.pop());
             }
             stack.push(tmp);
         }

         return stack;
        }

     public static void main(String[] args) {
         TwoStacks ts = new TwoStacks();
         int [] numbers = {1,3,2,6,5};
         ArrayList<Integer> al = ts.twoStacksSort(numbers);
         for(int i=0; i<al.size(); i++){
             System.out.print(al.get(i) + "  ");
         }
    }

} 
