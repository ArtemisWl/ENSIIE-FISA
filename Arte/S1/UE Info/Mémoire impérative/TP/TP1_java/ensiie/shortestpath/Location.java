package ensiie.shortestpath;

public class Location {
    private String name;
    private double latitude;
    private double longitude;
    private Location[] neighbors;
    private double distance;

    public Location(String nameNew, double latitudeNew, double longitudeNew) {
        name = nameNew;
        latitude = (Math.PI*latitudeNew)/180;
        longitude = (Math.PI*longitudeNew)/180;
        //distance = Math.random()*100;
    }

    public void display() {
        System.out.println("Nom : " + name + ", Latitude : " + latitude + ", Longitude : " + longitude);
    }


    public double distanceTo(Location to) {
        return (6378*(Math.PI/2 - Math.asin(Math.sin(to.latitude)*Math.sin(latitude) + Math.cos(to.longitude - longitude)*Math.cos(to.latitude)*Math.cos(latitude))));
    }

    public void setNeighbors(Location... neighbors) {
        this.neighbors = neighbors;
    }

    public double getDistance() {
        return distance;
    }
}

