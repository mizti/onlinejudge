require './island_counter'
describe IslandCounter do
  it "should have map as array" do
    ic = IslandCounter.new([[1],[1]])
    ic.map.class.should == Array
  end
  it "should return neighbors" do
    ic = IslandCounter.new([[1,1],[1,1],[0,8]])
    ic.map.length.should == 3
    ic.map[0].length.should == 2
    ic.neighbors(0,0).should == [[0,1],[1,0],[1,1]]
    ic.neighbors(1,1).should == [[0,0],[0,1],[1,0]]
  end

  it "should return neighbors2" do
    ic = IslandCounter.new([[1,1,1],[1,1,1],[1,0,1],[1,1,1]])
    ic.neighbors(0,0).should == [[0,1],[1,0],[1,1]]
    ic.neighbors(3,2).should == [[2,2],[3,1]]
    ic.neighbors(1,1).should == [[0,0],[0,1],[0,2],[1,0],[1,2],[2,0],[2,2]]
  end
  it "should return neighbors" do
    ic = IslandCounter.new([[0]])
    ic.neighbors(0,0).should == []
  end
  it "should return a new color" do
    ic = IslandCounter.new([[2,3,3],[1,2,3],[0,8,3],[5,63,3]])
    ic.largest_color.should == 63
  end
  it "should return from explorering" do
    ic = IslandCounter.new([[1,1,1],[1,0,1],[0,0,0],[1,1,1]])
    ic.explorer_in_an_island(0,0)
    ic.map.should == [[2, 2, 2], [2, 0, 2], [0, 0, 0], [1, 1, 1]]
  end
  it "should return from explorering" do
    ic = IslandCounter.new([[2, 2, 2], [2, 0, 2], [0, 0, 0], [1, 1, 1]])
    ic.explorer_in_an_island(3,1)
    ic.map.should == [[2, 2, 2], [2, 0, 2], [0, 0, 0], [3, 3, 3]]
  end

  it "should return the coord of new island" do
    ic = IslandCounter.new([[2, 2, 2], [2, 0, 2], [0, 0, 0], [1, 1, 1]])
    ic.find_new_island.should == [3, 0]
  end
  it "should return the coord of new island" do
    ic = IslandCounter.new([[2, 2, 2], [2, 0, 2], [0, 0, 0], [0, 1, 1]])
    ic.find_new_island.should == [3, 1]
  end
  it "should return nil if there is no remaining unexplorered island" do
    ic = IslandCounter.new([[2, 2, 2], [2, 0, 2], [0, 0, 0], [3, 3, 3]])
    ic.find_new_island.should == nil
  end
end
