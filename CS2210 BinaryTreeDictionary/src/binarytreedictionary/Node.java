/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package binarytreedictionary;

/**
 *
 * @author Eric Robinson
 */
public class Node{

        String word;
        int count;
        Node left;
        Node right;

    public Node() {
    }


    public Node(String word, int count, Node left, Node right) {
        this.word = word;
        this.count = count;
        this.left = left;
        this.right = right;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public Node getLeft() {
        return left;
    }

    public void setLeft(Node left) {
        this.left = left;
    }

    public Node getRight() {
        return right;
    }

    public void setRight(Node right) {
        this.right = right;
    }

    public String getWord() {
        return word;
    }

    public void setWord(String word) {
        this.word = word;
    }

    



}
