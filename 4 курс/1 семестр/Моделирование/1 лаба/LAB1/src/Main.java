public class Main {

    static void drawDiagram(int[] s, int[] a, int[] b, int[] c) { //отрисовка диаграммы Ганта
        System.out.print("A|");
        for (int i = 0; i < s.length; ++i){
            for (int j = 0; j < a[ s[i] - 1 ]; ++j)
                System.out.print(s[i]);
        }

        System.out.print("\nB|");
        for (int i = 0; i < s.length; ++i){
            int x;
            if (i == 0)
                x = a[s[i] - 1];
            else
                x = Math.max(a[s[i] - 1] - b[s[i - 1] - 1], 0);
            for (int j = 0; j < x; ++j)
                System.out.print("x");
            for (int j = 0; j < b[s[i] - 1]; ++j)
                System.out.print(s[i]);
        }

        System.out.print("\nC|");
        for (int i = 0; i < s.length; ++i){
            int x;
            int y;
            if (i == 0){
                x = a[ s[i] - 1];
                y = x + b[ s[i] - 1];
            }
            else{
                x = Math.max(a[ s[i] - 1] - b[s[i - 1] - 1], 0);
                y = Math.max(x + b[ s[i] - 1] - c[s[i - 1] - 1], 0);
            }

            for (int j = 0; j < y; ++j)
                System.out.print("y");

            for (int j = 0; j < c[s[i] - 1]; ++j)
                System.out.print(s[i]);
        }

        System.out.println("\nTime: " + CalculatTime(s, a, b, c));

    }
    static void print(int[] s, int[] a, int[] b, int[] c)
    {
        System.out.printf("%3c%3c%3c%3c\n", 'N', 'A', 'B', 'C');

        for (int i = 0; i < a.length; ++i)
        {
            System.out.printf("%3d%3d%3d%3d\n", s[i], a[s[i] - 1 ], b[ s[i] - 1 ], c[ s[i] - 1 ]);
        }
    }

    static void print(int[] s, int[] d, int[] e) {
        System.out.printf("%3c%3c%3c\n", 'N', 'D', 'E');

        for(int i = 0; i < d.length; ++i) {
            System.out.printf("%3d%3d%3d\n", s[i], d[i], e[i]);
        }

    }

    static int CalculatTime(int[] s, int[] a, int[] b, int[] c){
        int maxKH = Integer.MIN_VALUE;
        int k = 0;
        int h = 0;
        int bPrev = 0;
        int cPrev = 0;
        int sumC = 0;

        for (int i = 0; i < s.length; ++i){
            sumC += c[s[i] -1];
            k = k + a[s[i] -1] - bPrev;
            bPrev = b[s[i] -1];

            h = h + b[s[i] -1] - cPrev;
            cPrev = c[s[i] -1];

            maxKH = ((k + h) > maxKH)? k + h : maxKH;
        }
        return sumC + maxKH;
    }


    static void jhonson(int[] s, int[] d, int[] e){
        int dIndex = 0;
        int eIndex = d.length;

        // пока для выбора не остается одна строка
        while (eIndex - dIndex > 1){
            int minD = e[dIndex];
            int minE = e[dIndex];
            int rowD = dIndex;
            int rowE = dIndex;

            // поиск наименьшего элемента
            for (int j = dIndex; j < eIndex; ++j) {
                if (minD > d[j]) {
                    minD = d[j];
                    rowD = j;
                }

                if (minE > e[j]) {
                    minE = e[j];
                    rowE = j;
                }
            }

            if (minD < minE) {
                int temp = s[dIndex];
                s[dIndex] = s[rowD];
                s[rowD] = temp;

                temp = d[dIndex];
                d[dIndex] = d[rowD];
                d[rowD] = temp;

                temp = e[dIndex];
                e[dIndex] = e[rowD];
                e[rowD] = temp;

                ++dIndex;
            }
            else {
                int temp = s[eIndex - 1];
                s[eIndex - 1] = s[rowE];
                s[rowE] = temp;

                temp = d[eIndex - 1];
                d[eIndex - 1] = d[rowE];
                d[rowE] = temp;

                temp = e[eIndex - 1];
                e[eIndex - 1] = e[rowE];
                e[rowE] = temp;

                --eIndex;
            }

        }
    }

    static boolean NextSet(int[] s)
    {
        int j = s.length - 2;
        while (j != -1 && s[j] >= s[j + 1]) j--;
        if (j == -1)
            return false; // больше перестановок нет

        int k = s.length - 1;
        while (s[j] >= s[k])
            k--;


        int temp = s[j];
        s[j] = s[k];
        s[k] = temp;


        int l = j + 1, r = s.length - 1; // сортируем оставшуюся часть последовательности
        while (l < r) {
            l++;
            r--;
            temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        }
        return true;
    }

    static int max(int[] a){
        int maxNum = a[0];
        for (int j : a) {
            if (j > maxNum)
                maxNum = j;
        }
        return maxNum;
    }

    static int min(int[] a){
        int minNum = a[0];
        for (int j : a) {
            if (j < minNum)
                minNum = j;
        }
        return minNum;
    }


    public static void main(String[] args) {
        int[] s = {1, 2, 3, 4, 5};
        int[] a = {11, 6, 7, 8, 11};
        int[] b = {15, 3, 4, 2, 6};
        int[] c = {11, 9, 9, 10, 8};

        System.out.println("Before");
        print(s, a, b, c);

        int maxB = max(b);
        int minA = min(a);
        int minC = min(c);


        System.out.println();
        System.out.println();
        drawDiagram(s, a, b, c);
        System.out.println();
        System.out.println();

        if ((minA >= maxB) || (minC >= maxB))
        {
            System.out.println("True: " + minA + " >= " + maxB + " || " + minC + " >= " + maxB);
            int[] e = c.clone(), d = a.clone();
            for (int i = 0; i < d.length; ++i)
            {
                d[i] += b[i];
                e[i] += b[i];
            }

            System.out.println();
            System.out.println();
            print(s, d, e);

            jhonson(s, d, e);
            System.out.println();
            System.out.println();

            print(s, d, e);
        } else {
            System.out.println("False: " + minA + " >= " + maxB + " || " + minC + " >= " + maxB);

            int[] sOpt = s;
            int timeOpt = CalculatTime(s, a, b, c);
            while (NextSet(s))
            {
                int time = CalculatTime(s, a, b ,c);
                if (time < timeOpt)
                {
                    timeOpt = time;
                    sOpt = s;
                }
            }
            s = sOpt;
        }

        System.out.println();
        System.out.println();

        print(s, a, b, c);

        System.out.println();
        System.out.println();

        drawDiagram(s, a, b, c);
        System.out.print("\nS opt:");
        for (int i = 0; i < s.length; ++i)
        {
            System.out.print(s[i] + " ");
        }
        System.out.println();

    }

}
