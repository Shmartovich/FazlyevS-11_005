package week5;

import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class main {
    public static class Product {
        private String name;
        private int quantity;


        Product(String name, int quantity) {
            this.name = name;
            this.quantity = quantity;
        }


        @Override
        public String toString() {
            return name + " " + quantity;
        }
    }


    public static void writeOrdersToFile(Map<String,Integer> products) {

        FileOutputStream fileOutStream = null;
        try {
            fileOutStream = new FileOutputStream("C:\\Git projects\\products.txt");

            String product = products.toString();
            byte[] buffer = product.getBytes();
            fileOutStream.write(buffer);
        }
        catch (IOException e) {
            System.out.println(e.getMessage());
        }
        finally {
            if (fileOutStream != null) {
                try {
                    fileOutStream.close();
                }
                catch (IOException e) {
                    System.out.println(e.getMessage());
                }
            }
        }
    }

    public static void readOrdersToFile(Map<String,Integer> products){
        FileInputStream fileInStream = null;
        try {
            fileInStream = new FileInputStream("C:\\Git projects\\products.txt");

            int i = -1;
            while ((i = fileInStream.read()) != -1){
                System.out.print((char) i);
            }
        }
        catch (IOException e){
            System.out.println(e.getMessage());
        }
        finally {
            if (fileInStream != null) {
                try{
                    fileInStream.close();
                }
                catch (IOException e) {
                    System.out.println(e.getMessage());
                }
            }
        }
    }





    public static void main(String  args [] ){
        Scanner scanner = new Scanner(System.in);
        Map<String, Integer> products = new HashMap<>();

        products.put("apple",120);
        products.put("appl",10);

        System.out.println("Adding.. (end to exit,remove to delete product,change to change amount of product)");

        while(true){

            System.out.println("Product's name ");
            String string = scanner.next();

            if(string.equals("end")){
                break;
            }


            System.out.println("Product's amount ");
            int amount = scanner.nextInt();

            if(products.containsKey(string)){
                int amountOfProduct = products.get(string);
                products.put(string,amount + amountOfProduct);
            }
            else{
                products.put(string,amount);
            }
        }


        readOrdersToFile(products);



    }
}
