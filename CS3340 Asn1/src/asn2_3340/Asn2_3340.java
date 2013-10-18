/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package asn2_3340;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;

/**
 *
 * @author ericrobinson
 */
public class Asn2_3340 {

    /**
     * @param args the command line arguments
     */
    public static Vector<Pixel> image = new Vector<Pixel>();
    public static UnionFind uf;
    public static int maxCols = 0;
    public static int maxRows = 0;

    public static void main(String[] args) throws FileNotFoundException, IOException {



        String file = null;
        if (args.length > 0) {
            file = args[0];

        } else {
            System.out.println("There was no img file in the argument");
            return;
        }

        /*
         * Insert girl.txt into a ArrayList of Pixel
         */


        try {
            BufferedReader reader = new BufferedReader(new FileReader(file));

            String line = reader.readLine();


            //image.add(new Pixel(0,0, ' '));
            int xcounter = 0;
            int ycounter = 0;
            while (line != null) {
                //System.out.println(line);
                char[] charinline = line.toCharArray();
                for (char c : charinline) {
                    image.add(new Pixel(xcounter, ycounter, c));

                    xcounter++;
                }
                ycounter++;
                maxCols = xcounter;
                xcounter = 0;
                line = reader.readLine();
            }
            maxRows = ycounter;
        } catch (FileNotFoundException fnf) {
            System.out.println("File not found");
        } catch (IOException ioe) {
            System.out.println("Read/Write Error");
        }

        uf = new UnionFind(image.size());
        
        

        //uf.union(maxCols, maxCols);
        for (int i = 1; i < maxCols; i++) {

            
                if (image.get(i).getValue() == image.get(i - 1).getValue()) {
                    uf.union(i - 1, i);
                }
            

        }

        for (int i = maxCols; i < image.size(); i++) {
            if (i > maxCols && i % maxCols != 1) {

                    if (image.get(i - maxCols).getValue() == image.get(i).getValue() && image.get(i - 1).getValue() == image.get(i).getValue()) {
                        uf.union(i - 1, i);
                        uf.union(i - maxCols, i);
                        
                    } else if (image.get(i).getValue() == image.get(i - 1).getValue()) {
                        uf.union(i - 1, i);
                    } else if (image.get(i - maxCols).getValue() == image.get(i).getValue()) {
                        uf.union(i - maxCols, i);
                    }
                } else if (i > maxCols && i % maxCols != 0) {
                    if (image.get(i - maxCols).getValue() == image.get(i).getValue()) {
                        uf.union(i - maxCols, i);
                    }
                }



            } 
        



        uf.Final_Sets();
        uf.printImage(maxCols);




    }
}
