package ensiie.shortestpath;

public class LocationSet {
    private Location[] locations;
    private int nbLocations;

    public LocationSet() {
        locations = null;
        nbLocations = 0;
    }

    public void add(Location location) {
        
        if(locations == null) {
            Location[] tmp1 = new Location[2];
            tmp1[0]= location;
            locations = tmp1;
        }
        else if (nbLocations == locations.length) {
            Location[] tmp2 = new Location[2+nbLocations];
            for(int i = 0; i < nbLocations; i++) {
                tmp2[i] = locations[i];
            }
            tmp2[nbLocations] = location;
            locations = tmp2;
        }
        else {
            locations[nbLocations] = location;
        }
        nbLocations++;
    }
}

