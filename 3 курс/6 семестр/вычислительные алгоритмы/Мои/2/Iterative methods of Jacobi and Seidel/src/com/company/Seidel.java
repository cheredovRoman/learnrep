package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Seidel {
    // Метод для печати матрицы в консоль и файл
    private static void printMatrix(double[][] matrix, double[] b, PrintWriter pw, int f){
        for (int i = 0; i < matrix.length; i++){
            for (int j = 0; j < matrix[0].length; j++) {
                if (f == 1) {
                    System.out.printf("%16f", matrix[i][j]);
                    pw.printf("%16f", matrix[i][j]);
                }else{
                    System.out.printf("%7.0f", matrix[i][j]);
                    pw.printf("%7.0f", matrix[i][j]);
                }

            }
            System.out.printf("%16f", b[i]);
            pw.printf("%16f", b[i]);
            System.out.println();
            pw.println();
        }
        System.out.println();
        pw.println();
    }

    // Альтернативный способ вычисления погрешности
    public static double normCalculation(double[] x0, double[] x1, int n) {
        double sum = 0;
        for (int i = 0; i <n; i++) {
            sum += Math.abs(x0[i]-x1[i]);
        }
        return sum;
    }
    // шапка таблицы
    public static void printTabel(PrintWriter pw, int a){
        if (a == 1) {
            System.out.println("________________________________________________________________________________________________________");
            System.out.println("|    i |                x1 |                x2 |                x3 |              eps1 |              eps2 |             eps3  |");
            System.out.println("--------------------------------------------------------------------------------------------------------");
            pw.println("________________________________________________________________________________________________________");
            pw.println("|    i |            x1 |            x2 |            x3 |          eps1 |          eps2 |         eps3  |");
            pw.println("--------------------------------------------------------------------------------------------------------");
        }
        if (a == 2) {
            System.out.println("--------------------------------------------------------------------------------------------------------");
            pw.println("---------------------------------------------------------------------------------------------------------");
        }
    }
    // Функция проверки погрешности
    public boolean checkEps(double[] eps, double enterEps){
        double max = 0;
        for (int i = 0; i < eps.length; i++) {
            if (max < eps[i])
                max = eps[i];
        }
        if (max < enterEps){
            return true;
        }
        return false;
    }
    // Вычисление нормы невязки
    public static double norm(List<Double> x){
        double max;
        max = 0;
        for (int i = 0; i < x.size(); i++) {
            if (Math.abs(x.get(i)) > Math.abs(max)) {
                max = x.get(i);
            }
        }
        return Math.abs(max);
    }
    // Вычисление невязки
    public static double discrepancy(double[][] a1, double[] b, double[] x){
        double a;
        List<Double> r = new ArrayList<>();
        for (int i = 0; i < a1.length; i++) {
            a = 0;
            for (int j = 0; j < a1[0].length; j++) {
                a = a + a1[i][j] * x[j];
            }
            r.add(b[i] - a);
        }
        return norm(r);
    }



    // Главный метод класса
    public void method() throws FileNotFoundException {
        //Чтение из файла и объявление переменных
        boolean view = false;
        File inputFile = new File("input.txt");
        PrintWriter pw = new PrintWriter("output.txt");
        Scanner scanner = new Scanner(inputFile);
        double eps = scanner.nextDouble();
        int n = scanner.nextInt();
        double[] x0 = new double[n];
        for (int i = 0; i < n; i++) {
            x0[i] = scanner.nextDouble();
        }
        double norm = Double.MAX_VALUE;
        double[] epsil = new double[n];
        double[] x = new double[n];
        double matrix[][] = new double[n][n];
        double b[] = new double[n];
        boolean checkDiverg = false; // Проверка на расходимость
        // Считывание матрицы из файла
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextDouble();
            }
            b[i] = scanner.nextDouble();
            //x0[i] = b[i] / matrix[i][i];
        }
        Scanner scan = new Scanner(System.in);
        pw.println("Метод Зейделя");
        // Вывод матрицы
        System.out.println("Заданная матрица:");
        pw.println("Заданная матрица:");
        printMatrix(matrix, b, pw, 1);
        int counter = 0;
        boolean repeat = false;
        if (view) printTabel(pw, 1);
        do { // Пока погрешность выше eps
            double[] tmp = new double[n];
            for (int i = 0; i < n; i++) {
                double sum = 0;
                double diverg = 0;
                for (int j = 0; j < n; j++) {
                    // (k-1) * на элемент не главной диагонали
                    if (i == j)
                        continue;
                    sum += matrix[i][j] * x0[j];
                    diverg += Math.abs(matrix[i][j]);
                }
                if (diverg > Math.abs(matrix[i][i]) && !repeat) { // Если есть расходимость
                    System.out.println("Условие итерации не выполняется, хотите продолжить выполнение программы? (1 - Да, 2 - Нет).");
                    if (scan.nextInt() == 2) {
                        checkDiverg = true;

                        break;
                    } else {
                        repeat = true;
                    }
                }

                x[i] = (b[i] - sum) / matrix[i][i];
                tmp[i] = x0[i];
                x0[i] = x[i];
            }
            if (view) System.out.printf("|%5d |", counter + 1);
            if (view) pw.printf("|%5d |", counter + 1);
            for (int i = 0; i < n; i++) {
                epsil[i] = Math.abs(x[i] - tmp[i]) / Math.abs(x[i]);
                x0[i] = x[i];
                if (view) System.out.printf("%17f |", x0[i]);
                if (view) pw.printf("%17f |", x0[i]);
            }
            counter++;

            for (int i = 0; i < n; i++) {
                if (view) System.out.printf("%17f |",  epsil[i]);
                if (view) pw.printf("%17f |", epsil[i]);
            }
            if (view) System.out.println();
            if (view) pw.println();

        }while (!checkEps(epsil, eps) && !checkDiverg);

        if (view) printTabel(pw, 2);
        if (checkDiverg) {
            System.out.println("Условие итерации не выполняется");
            pw.println("Условие итерации не выполняется");
        }else {
            System.out.println(counter + " итераций");
            pw.println(counter + " итераций");
            for (int i = 0; i < n; i++) {
                System.out.printf(Locale.US, "x%d = %f\n", i, x0[i]);
                pw.printf(Locale.US, "x%d = %f\n", i, x0[i]);
            }
        }
        System.out.println("Норма невязки: " + discrepancy(matrix, b, x));
        pw.println("Норма невязки: " + discrepancy(matrix, b, x));
        // закрываем файл
        pw.flush();
        pw.close();

    }
}
