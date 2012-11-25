class Cell
  # このセルにウィルスがいるか
  attr_accessor :infected
  # 自分の上下左右のcellオブジェクトを持つ
  attr_accessor :up, :down, :left, :right
  # このcellが既に評価されたか
  attr_accessor :evaluated
  # エリアナンバー
  attr_accessor :area_no

  def initialize(infected)
    @infected = infected
    @evaluated = false
    @evaluated = true if @infected == false
  end

  # このセルのarea_noを評価する関数
  def eval(area_no = nil)
    return if evaluated

    if area_no 
      @area_no = area_no
    else
      @area_no = $area_no
      $area_no += 1
    end

    @evaluated = true
    check_neighbor(@area_no)
  end

  def check_neighbor(area_no)
    @up.eval(area_no)     if @up
    @down.eval(area_no)   if @down
    @left.eval(area_no)   if @left
    @right.eval(area_no)  if @right
  end

end


###  Main Function
def main
  loop do 
    $area_no = 0 

    # 全体サイズの読み込み
    size = STDIN.gets.chomp.split(' ')
  
    size_x = size[0].to_i
    size_y = size[1].to_i

    break if size_x == 0 && size_y == 0

    # 情報の読み込み
    cellmap = Array.new
    size_y.times do |count|
      cell_row = Array.new
      STDIN.gets.chomp.split(' ').each do |element|
        if element == "0"
          cell_row << Cell.new(false)
        else
          cell_row << Cell.new(true)
        end
      end
      cellmap << cell_row
    end

    # セル同士の紐付けを行う
    size_y.times do |y|
      size_x.times do |x|
        cellmap[y][x].up    = cellmap[y - 1][x] if y > 0
        cellmap[y][x].down  = cellmap[y + 1][x] if y < size_y - 1 
        cellmap[y][x].left  = cellmap[y][x - 1] if x > 0 
        cellmap[y][x].right = cellmap[y][x + 1] if x < size_x - 1
      end
    end

    # すべてのセルを評価する
    cellmap.flatten.each do |cell|
      cell.eval
    end

    puts "A number of infected area is #{$area_no}."
  end
end

main

