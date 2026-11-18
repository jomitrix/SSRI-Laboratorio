public class Matrix {
    private int rows, columns;
    private int m[][];

    Matrix(int rows, int columns) {
        this.rows = rows;
        this.columns = columns;
        this.m = new int[3][3];
    }

    Matrix(int[][] existent) {
        this.rows = existent.length;
        this.columns = existent[0].length;
        this.m = existent;
    }

    Matrix(Matrix existent) {
        this.rows = existent.rows;
        this.columns = existent.columns;
        this.m = existent.m;
    }

    void setValore(int i, int j, int value) {
        m[i][j] = value;
    }

    int getValore(int i, int j) {
        return m[i][j];
    }

    int rows() {
        return this.rows;
    }

    int columns() {
        return this.columns;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            System.out.print("[  ");
            for (int j = 0; j < columns; j++) {
                System.out.print(m[i][j] + "  ");
            }
            System.out.println("]");
        }
        System.out.println();
    }

    Matrix sum(Matrix addendo) {
        if (this.rows == addendo.rows && this.columns == addendo.columns) {
            int[][] result = new int[rows][columns];

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    result[i][j] = this.m[i][j] + addendo.m[i][j];
                }
            }

            return new Matrix(result);
        } else {
            System.out.printf("\nERRORE: Le dimensioni delle matrici non corrispondono. Questa matrice è %dx%d, mentre l'addendo è %dx%d.\n", this.rows, this.columns, addendo.rows, addendo.columns);
            return new Matrix(0, 0);
        }
    }

    Matrix multiply(Matrix multiplier) {
        if (this.columns == multiplier.rows) {
            int[][] result = new int[this.rows][multiplier.columns];

            for (int i = 0; i < this.rows; i++) {
                for (int j = 0; j < multiplier.columns; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < this.columns; k++) {
                        result[i][j] += this.m[i][k] * multiplier.m[k][j];
                    }
                }
            }

            return new Matrix(result);
        } else {
            System.out.printf("\nERRORE: Le righe del moltiplicatore devono essere uguali alle colonne di questa matrice.\n");
            return new Matrix(0, 0);
        }
    }

    Matrix scalar(int scalar) {
        int[][] result = new int[rows][columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result[i][j] = this.m[i][j] * scalar;
            }
        }

        return new Matrix(result);
    }
}
