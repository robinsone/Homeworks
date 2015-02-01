/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment_1;

import java.io.*;

/**
 *
 * @author Eric Robinson
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static int[] StudentID = new int[20];
    public static float[] ClassAvg = new float[20];
    public static float[] StudentAvg = new float[20];

    public static void main(String[] args) {
        // TODO code application logic here
        buildArray();
        System.out.println("Unsorted Array");
        System.out.println("");
        displayArray();
        System.out.println("");
        System.out.println("Sorted Array");
        System.out.println("");
        sortArray();
        displayArray();
        System.out.println("");
        System.out.println("Search Array");
        System.out.println("");
        searchArray();


    }

    public static void sortArray() {
        boolean doMore = true;
        while (doMore) {
            doMore = false;  // assume this is last pass over array
            for (int i = 0; i < StudentID.length - 1; i++) {
                if (StudentID[i] > StudentID[i + 1]) {
                    // exchange elements
                    int temp = StudentID[i];
                    StudentID[i] = StudentID[i + 1];
                    StudentID[i + 1] = temp;
                    float temp2 = ClassAvg[i];
                    ClassAvg[i] = ClassAvg[i + 1];
                    ClassAvg[i + 1] = temp2;
                    float temp3 = StudentAvg[i];
                    StudentAvg[i] = StudentAvg[i + 1];
                    StudentAvg[i + 1] = temp3;
                    doMore = true;  // after an exchange, must look again
                }
            }
        }


    }

    private static void buildArray() {

        StringBuilder contents = new StringBuilder();

        try {

            BufferedReader input = new BufferedReader(new FileReader("C:/Users/Eric Robinson/Documents/Algoma Courses Semester 1/COSC 2006 –Data Structures I/Assignment I/Assignment_1/src/assignment_1/averages.txt"));
            try {
                String line = null; //not declared within while loop
                int count = 0;
                int arraycount = 0;


                while ((line = input.readLine()) != null) {
                    contents.append(line);
                    if (count == 0) {
                        StudentID[arraycount] = Integer.parseInt(line.trim());
                        count++;

                    } else if (count == 1) {
                        ClassAvg[arraycount] = Float.parseFloat(line.trim());
                        count++;

                    } else if (count == 2) {
                        StudentAvg[arraycount] = Float.parseFloat(line.trim());
                        count = 0;
                        arraycount++;
                    }


                }
            } finally {
                input.close();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }



    }

    private static void displayArray() {


        int j = 0;

        for (int u : StudentID) {

            if (u != 0) {

                System.out.println(u);
                System.out.println(StudentAvg[j]);
                System.out.println(ClassAvg[j]);


            }

            j++;
        }


    }

    private static void displayAllArray() {


        int x = 0;

        for (int i : StudentID) {

            if (i != 0) {

                System.out.println(i);
                System.out.println(StudentID[x]);
                System.out.println(StudentID[x]);
                x++;

            }


        }
        for (float i : ClassAvg) {

            if (i != 0) {

                System.out.println(i);
                System.out.println(ClassAvg[x]);
                System.out.println(ClassAvg[x]);
                x++;

            }


        }
        for (float i : StudentAvg) {

            if (i != 0) {

                System.out.println(i);
                System.out.println(StudentAvg[x]);
                System.out.println(StudentAvg[x]);
                x++;

            }


        }


    }

    public static void searchArray() {
        BufferedReader dataIn = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Search: ");
        String search = "";
        try {
            search = dataIn.readLine();
        } catch (IOException e) {
            System.out.println("Error!");
        }
        int x = 0;
        for (int i : StudentID) {

            if (search.equals(Integer.toString(i))) {
                System.out.println("result is: " + i + " " + StudentAvg[x] + " " + ClassAvg[x]);

            }
            x++;
        }

    }
}
