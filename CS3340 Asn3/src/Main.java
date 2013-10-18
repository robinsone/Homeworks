/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Vector;

/**
 *
 * @author ericrobinson
 */
public class Main {
    
    public static Vector<WeightedEdges> graph = new Vector<WeightedEdges>();
    public static int numVertex;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
         String file = null;
        if (args.length > 0) {
            file = args[0];

        } else {
            System.out.println("There was no img file in the argument");
            return;
        }

        try {
            BufferedReader reader = new BufferedReader(new FileReader(file));

            String line = reader.readLine();

            numVertex = Integer.parseInt(line);
          
            while ((line = reader.readLine()) != null) {
                
                StringTokenizer st = new StringTokenizer(line);
                while (st.hasMoreTokens()) {
                    
                        int id = Integer.parseInt(st.nextToken());
                        int dest = Integer.parseInt(st.nextToken());
                        int weight = Integer.parseInt(st.nextToken());
                        //System.out.println("id: " + id + " ,dest: " + dest + " ,weight " + weight);
                        graph.add(new WeightedEdges(weight, dest, id));
                        Collections.sort(graph);
                        
                }
                
            }
        } catch (FileNotFoundException fnf) {
            System.out.println("File not found, " + fnf.toString());
        } catch (IOException ioe) {
            System.out.println("Read/Write Error, " + ioe.toString());
        }
        
        System.out.println("Input Graph:");
        System.out.println("V1\tV2\tWeight");
        for(WeightedEdges w : graph){
            System.out.println(w._v2+ "\t" +w._v1+ "\t" + w._weight);
        }
        
        UnionFind uf = new UnionFind(numVertex);
        Vector<WeightedEdges> finalEdges = new Vector<WeightedEdges>();
        
        while(!graph.isEmpty()){
        //for(int i = 0; i < graph.size(); i++){
            WeightedEdges e = graph.remove(graph.indexOf(graph.firstElement()));
            if(uf.find(e._v1-1) != uf.find(e._v2-1)){
                finalEdges.add(e);
                uf.union(e._v1-1, e._v2-1);
            }
        }
        
        System.out.println("\n\n");
        System.out.println("Minimum Cost Spanning Tree:");
        System.out.println("V1\tV2\tWeight");
        
         for(WeightedEdges w : finalEdges){
            System.out.println(w._v2+ "\t" +w._v1+ "\t" + w._weight);
        }
        
        
    }
}
