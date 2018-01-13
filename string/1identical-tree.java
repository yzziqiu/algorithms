/* applied-strings
# 拓扑结构相同子树
# 对于两棵彼此独立的二叉树A和B，请编写一个高效算法，检查A中是否存在一棵子树与B树的拓扑结构完全相同。
# 给定两棵二叉树的头结点A和B，请返回一个bool值，代表A中是否存在一棵同构于B的子树。
# 首先将两个树转换为字符串，遍历这棵树注意在为空的地方加上#！
# 这样可以保证树的唯一性，另外每一个节点后面要跟上#这样可以区分12和1 2这样的节点。
# 之后利用KMP算法可以将字符串匹配的算法复杂度降到O(M+N）M和N是字符串的长度。
*/
import java.util.*;
/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    public TreeNode(int val) {
        this.val = val;
    }
}*/
public class IdenticalTree
{
  public boolean chkIdentical(TreeNode A, TreeNode B)
  {
    String a1=treetostring(A);
    String b1=treetostring(B);
    return a1.contains(b1);
  }
  public String treetostring(TreeNode h)
  {
    if (h==null)
    {
      return "#!";
    }
    else
    {
        String str=h.val+"!";
        str+=treetostring(h.left);
        str+=treetostring(h.right);
        return str;
      }
    }

}
