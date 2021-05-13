package week10_StreamAPI;

import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main2 {
    static int findNumber(int x){
        int count = 10;
        while(x>0){
            count++;
            x= x/10;
        }
        return count;
    }

    public static void main(String [] args) {
        System.out.println("Задание 2 отсортировать по концу, удалить конец");

        Integer [] ints = new Integer [] {123,231,312,123,1232134,431,123};


        Stream<Integer> stream = Arrays.stream(ints);



        stream
                .sorted((x,y)-> Integer.compare(x%10,y%10))

                .distinct()
                .forEach(x->System.out.println(x));

    }
}
