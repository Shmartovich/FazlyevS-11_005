package week10_StreamAPI;

import java.util.Arrays;
import java.util.stream.Stream;

public class Main {
    public static void main(String [] args){
        System.out.println("Задание 1 начинается на а, сортируется по длине");

        String [] strings = new String [] {"adfad","adb","er","geragagr","ada","gtbaeat","aba","tgetsga"};
        Stream<String> stream = Arrays.stream(strings);
        stream.filter(x->x.charAt(0)=='a')
                .sorted((a,b)-> Integer.compare(a.length(),b.length()))
                .forEach(System.out::println);


    }
}
