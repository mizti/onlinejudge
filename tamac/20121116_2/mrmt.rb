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
  # 全体サイズの読み込み
  size = STDIN.gets.chomp.split(' ')

  if size[0] != size[1]
    puts "cell size error!"
    exit
  end

  size = size[0].to_i

  # 情報の読み込み
  cellmap = Array.new
  size.times do |count|
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
  size.times do |i|
    size.times do |j|
      cellmap[i][j].up    = cellmap[i - 1][j] if i > 0
      cellmap[i][j].down  = cellmap[i + 1][j] if i < size - 1 
      cellmap[i][j].left  = cellmap[i][j - 1] if j > 0 
      cellmap[i][j].right = cellmap[i][j + 1] if j < size - 1
    end
  end

  # すべてのセルを評価する
  cellmap.flatten.each do |cell|
    cell.eval
  end

  puts "A number of infected area is #{$area_no}."
end

$area_no = 0 
main

