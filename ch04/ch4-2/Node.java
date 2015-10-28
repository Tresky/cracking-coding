public class Node{
    private int num;
    public Node left;
    public Node right;

    public Node(int number){
        num = number;
        left = null;
        right = null;
    }

    public void setNumber(int number){
        this.num = number;
    }

    public int getNumber(){
        return this.num;
    }

}