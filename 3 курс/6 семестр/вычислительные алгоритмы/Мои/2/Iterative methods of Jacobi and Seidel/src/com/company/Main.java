package com.company;
import java.io.*;
import java.util.Scanner;


public class Main {

    public static void main(String args[]) throws IOException {

        Scanner scanner = new Scanner(System.in);
        Jacoby jacoby = new Jacoby();
        Seidel seidel = new Seidel();

        System.out.println("Сделать расчеты по методу Якоби (1), Зейделя(2)");
        if (scanner.nextInt() == 2){
            seidel.method();//вызов метода Зейделя
        }else{
            jacoby.method();//вызов метода Якоби
        }
    }
}



