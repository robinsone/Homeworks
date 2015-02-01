/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package twothreetree;

/**
 *
 * @author Eric Robinson
 */
public class Node {

    private keyItem small, big;
    private Node left, middle, right;

    public Node() {
    }

    public Node(keyItem small, keyItem big, Node left, Node middle, Node right) {
        this.small = small;
        this.big = big;
        this.left = left;
        this.middle = middle;
        this.right = right;
    }


    public boolean hasChild(){
        if(this.left != null || this.right != null || this.middle != null)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public keyItem getBig() {
        return big;
    }

    public void setBig(keyItem big) {
        this.big = big;
    }

    public Node getLeft() {
        return left;
    }

    public void setLeft(Node left) {
        this.left = left;
    }

    public Node getMiddle() {
        return middle;
    }

    public void setMiddle(Node middle) {
        this.middle = middle;
    }

    public Node getRight() {
        return right;
    }

    public void setRight(Node right) {
        this.right = right;
    }

    public keyItem getSmall() {
        return small;
    }

    public void setSmall(keyItem small) {
        this.small = small;
    }

        

    
}
