/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package asn2_3340;

import java.util.*;

public class UnionFind {

    private int[] array;
    private Vector<Integer> finalarray = new Vector<Integer>();
    private int[] id;    // id[i] = parent of i
    private int[] sz;    // sz[i] = number of objects in subtree rooted at i
    private int count;   // number of components

    /**
     * Create an empty union find data structure with N isolated sets.
     */
    public UnionFind(int N) {
        count = N;
        id = new int[N];
        sz = new int[N];
        id[0] = 0;
        for (int i = 1; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    /**
     * Return the id of component corresponding to object p.
     */
    public int find(int p) {
        while (p != id[p]) {
            p = id[p];
        }
        return p;
    }

    /**
     * Return the number of disjoint sets.
     */
    public int count() {
        return count;
    }

    /**
     * Are objects p and q in the same set?
     */
    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    /**
     * Replace sets containing p and q with their union.
     */
    public void union(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) {
            return;
        }

        // make smaller root point to larger one
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        count--;
    }

    public void Final_Sets() {
        
        finalarray = new Vector<Integer>();
        finalarray.add(0);

        for (int i = 0; i < id.length; i++) {
            boolean exists = false;
            for (int x = 0; x < finalarray.size(); x++) {
                if (id[i] == finalarray.get(x)) {
                    exists = true;
                }
            }
            if (!exists) {
                finalarray.add(id[i]);
               
            }
        }

       
    }
    
    public void printImage(int maxCols){
        int xcounter = 0;
        int ycounter = 0;

        String output = "";
        for (int i = 0; i < id.length; i++) {
            if (xcounter == maxCols) {
                output += '\n';
                xcounter = 0;
            }
           
            char digit = (char) ((char) 63 + finalarray.indexOf(id[i])) ;
            if(digit == '@') digit = ' ';
            output +=  digit;
            xcounter++;


        }
        System.out.println(output);
    }
    /*
     * Vector<Node> sets = new Vector();
     *
     * public UnionFind() { }
     *
     * public void uandf(Vector<Pixel> pixels){ for(Pixel p : pixels){
     * sets.add(new Node(p)); } }
     *
     * public void Make_Set(int i){
     *
     * }
     *
     * public int Find_Set(int i){ if(sets.get(i) == sets.get(1).getParent()){
     * return i; }else{ i = Find_Set(sets.indexOf(sets.get(i).getParent()));
     * return i; } }
     *
     *
     */
}
