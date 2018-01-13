/*
6数组变树
*/
package Tree;


import java.util.ArrayList;
import java.util.List;

/**
 * Created by ykanghe on 2016/9/7.
 */
public class BinTree {

    private int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    private static List<Node> nodeLIst = new ArrayList<Node>();

    private static class Node {
        Node leftChild;
        Node rightChidl;
        int data;

        Node(int data) {
            this.data = data;
        }
    }

    public void createBintree() {
        for (int i = 0; i < array.length; i++) {
            nodeLIst.add(new Node(array[i]));
        }

        if (nodeLIst.size() > 0) {
            for (int y = 0; y < array.length / 2 - 1; y++) {
                //leftChild
                if (null != nodeLIst.get(2 * y + 1)) {
                    nodeLIst.get(y).leftChild = nodeLIst.get(2 * y + 1);
                }
                //rightChild
                if (null != nodeLIst.get(2 * y + 2)) {
                    nodeLIst.get(y).rightChidl = nodeLIst.get(2 * y + 2);
                }
            }
            //最后一个父节点不一定有孩子
            int lastParentIndex = array.length / 2 - 1;
            // 左孩子
            nodeLIst.get(lastParentIndex).leftChild = nodeLIst
                    .get(lastParentIndex * 2 + 1);
            //奇数时候有右孩子
            if (array.length % 2 == 1) {
                nodeLIst.get(lastParentIndex).rightChidl = nodeLIst
                        .get(lastParentIndex * 2 + 2);
            }
        }
    }

    /**
     * 先序遍历
     *
     * @param node
     */
    public static void preOrderTraver(Node node) {
        if (null != node) {
            System.out.println("node:" + node.data);
            preOrderTraver(node.leftChild);
            preOrderTraver(node.rightChidl);
        } else {
            return;
        }
    }

    public static void main(String[] args) {
        BinTree tree = new BinTree();
        tree.createBintree();
        preOrderTraver(nodeLIst.get(0));
    }

}
