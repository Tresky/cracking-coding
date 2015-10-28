import java.io.*;
import java.util.*;

public class ArrayToTree{

    public static void main(String[] args){
        int middle;
        int[] sortedArray = {1, 4, 9, 21, 23, 24, 25, 89, 102};

        

        Node tree = buildTree(sortedArray, 0, sortedArray.length-1);

        Display(tree, 0);
    }

    public static Node buildTree(int[] _array, int start, int end){

        if(start > end)
            return null;

        int middle = (start+end)%2 + (start + end)/2;
        Node node = new Node(middle);
        node.left = buildTree(_array, start, middle -1);
        node.right = buildTree(_array, middle + 1, end);
        return node;
    }



    public static void Display(Node _node, int _layer)
    {
        if (_node == null) {
            // for (int i = 0; i < _layer; i++)
            //     cout << "\t";
        }
        else
        {
            Display(_node.right, _layer + 1);
            for (int i = 0; i < _layer; i++)
                System.out.print("\t");
            System.out.println(_node.getNumber());
            Display(_node.left, _layer + 1);
        }
    }
}