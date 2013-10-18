

import java.util.*;

public class UnionFind {
    
    /*
     *  uandf(n): constructs an union-find data type with n elements, 1, 2, . . . , n.
        
        make set(i): creates a new set whose only member (and thus representative) is i.
       
        union sets(i,j): unites the dynamic sets that contains i and j, respectively, 
         into a new set that is the union of these two sets.
        
        find set(i): returns the representative of the set containing i.
        
        final sets(): returns the total number of current sets, finalizes the 
         current sets (make set() and union sets() will have no effect after this 
         operation), and resets the representatives of the sets so that integers 
       * from 1 to final sets() will be used as representatives.
     */
    
    /*
     * Notes to TA. 
     * 
     * uandf = Unionfind Function;
     * Union sets = union
     * find set(i) = find
     * final sets(i) is actually implemented in asn2_3340.java
     * 
     */

    /**
     * The trees of Nodes that represent the disjoint sets.
     */
    Node[] nodes;
    Node[] stack;

    
    /*
     * I used Union Find instead of uandf
     */
    public UnionFind(int size) 
    {
        nodes = new Node[size];
        stack = new Node[size];
    }

   
    private Node findNode(int a) 
    {
        Node na = nodes[a];
        return makeset(na,a);
    }

    private Node makeset(Node na, int a)
    {
        if (na == null) {
            // Start a new set with a
            Node root = new Node(a);

            root.child = new Node(a);
            root.child.parent = root;

            nodes[a] = root.child;

            return root;
        }

        return findNode(na);
    }


    public int find(int a) 
    {
        return findNode(a).value;
    }

    /**
     * Finds the set containing a given Node.
     */
    private Node findNode(Node node) 
    {
        int top = 0;

        while (node.parent.child == null) {
            stack[top++] = node;
            node = node.parent;
        }

        Node rootChild = node;

        while (top > 0) {
            node = stack[--top];
            node.parent = rootChild;
        }

        return rootChild.parent;
    }

    /**
     * Returns true if a and b are in the same set.
     */
    public boolean isEquiv(int a, int b) {
        return findNode(a) == findNode(b);
    }

    /**
     * Combines the set that contains a with the set that contains b.
     */
    public void union(int a, int b) 
    {
        Node na = findNode(a);
        Node nb = findNode(b);

        if (na == nb) {
            return;
        }

        // Link the smaller tree under the larger.
        if (na.rank > nb.rank) {
            // Delete nb.
            nb.child.parent = na.child;
            na.value = b;
        } else {
            // Delete na.
            na.child.parent = nb.child;
            nb.value = b;

            if (na.rank == nb.rank) {
                nb.rank++;
            }
        }
    }

   
}
