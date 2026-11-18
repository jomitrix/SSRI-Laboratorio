public class Password {
    private String pass;
    private final int minChar = 8;
    private final int minUpper = 0;
    private final int minLower = 2;

    Password(String pass) throws Exception {
        if (isValid(pass)) {
            this.pass = pass;
        } else {
            throw new Exception("Il numero deve avere\n- almeno 8 caratteri\n- solo lettere e numeri\n- almeno 2 caratteri");
        }
    }

    boolean isValid(String str) {
        return isMinimumCharRequired(str) && isOnlyLettersAndCharacters(str) && hasAtLeastNNumbers(str) && hasAtLeastNLower(str) && hasAtLeastNUpper(str);
    }

    private boolean isMinimumCharRequired(String str) {
        return str.length() >= minChar;
    }

    private boolean isOnlyLettersAndCharacters(String str) {
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (!(Character.isDigit(c) || Character.isLowerCase(c) || Character.isUpperCase(c))) {
                return false;
            }
        }
        return true;
    }

    private boolean hasAtLeastNNumbers(String str) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (Character.isDigit(str.charAt(i))) {
                count++;
            }
            if (count >= 2) {
                return true;
            }
        }
        return false;
    }

    private boolean hasAtLeastNLower(String str) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (Character.isLowerCase(str.charAt(i))) {
                count++;
            }
            if (count >= minLower) {
                return true;
            }
        }
        return false;
    }

    private boolean hasAtLeastNUpper(String str) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (Character.isUpperCase(str.charAt(i))) {
                count++;
            }
            if (count >= minUpper) {
                return true;
            }
        }
        return false;
    }
}