

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ericrobinson
 */
 public class Node {

        Node parent;  // The root of the tree in which this Node resides
        Node child;
        int value;
        int rank;     // This Node's height in the tree

        public Node(int v) {
            value = v;
            rank = 0;
        }
    }
