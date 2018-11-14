public class StateArray
{
  public static void main(String args[])
  {
    Scanner fileScan = new Scanner(new File("StateData.txt"));
    List<State> stateArray = new ArrayList<State>;

    while (fileScan.hasNext())
    {
      String fileRecord = fileScan.nextLine();
      String lineScan = new Scanner(fileRecord);
      lineScan.useDelimiter(",");

      String stateName = lineScan.next();
      String stateCapital = lineScan.next();
      String stateBird = lineScan.next();
      String stateFlower = lineScan.next();
      String stateNickName = lineScan.next();
      String dateEnteredUnion = lineScan.next();
      int yearSettled = int(lineScan.next());

      State currentState = new State(stateName, stateCapital, stateBird, stateFlower, stateNickName, dateEnteredUnion, yearSettled);
      stateArray.add(currentState);
    }
  }
}
