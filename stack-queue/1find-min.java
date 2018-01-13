/*
1.可查询最值的栈
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/
import java.util.Stack;

public class Solution {
    Stack a = new Stack();
    Stack b = new Stack();

    public void push(int node) {
        a.push(node);
        if(b.empty())b.push(node);
        else{
            if(node < (int)b.peek())
                b.push(node);
            else
                b.push(b.peek());
        }
    }

    public void pop() {
        a.pop();
        b.pop();
    }

    public int top() {
        return (int) a.peek();
    }

    public int min() {
        return (int) b.peek();
    }
}
