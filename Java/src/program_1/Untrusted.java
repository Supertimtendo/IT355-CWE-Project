package program_1;

public class Untrusted {
    public static void potentiallyDangerousMethod(Black_Mage bm){
        bm.setLevel(-9999);
        bm.setName("get pwnd");
        String[] newData = {"oh","no","it's","all","gone!!!!"};
        bm.setSensitiveData(newData);
    }
}
