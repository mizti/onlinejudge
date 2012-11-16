class PolishProcessor
  attr_accessor :arr
  def initialize(s)
    #与えられた文字列を解析して配列に入れる
    @arr = arraynize(s)
  end
  def evaluate
    @stack = []

    # arrが空になるまで、末尾から一つづつ数字を取り出す
    while((popped = @arr.pop) != nil) do
      if Integer === popped then
        # 取り出されたのが数字だったら、スタックに積む
        @stack.push popped
      end
      if popped == "+" || popped == "*" || popped == "-" then
        # 取り出されたのが演算子だったら、スタックにつまれた数字2つを取り出して計算してまたスタックに積む
        num1 = @stack.pop
        num2 = @stack.pop
        @stack.push calc(popped, num1, num2)
      end
    end
    @stack[0]
  end

  # 与えられた演算子と数字2つから計算を行う
  def calc(operator, num1, num2)
    if operator == "+" then
      return num1 + num2
    elsif operator == "*" then
      return num1 * num2
    elsif operator == "-" then
      return num1 - num2
    else
      return "Error"
    end
  end

  # 与えられた文字列を分解して配列に入れる
  def arraynize(s)
    ret = s.gsub("("," ").gsub(")", " ").split(/\s* \s*/)
    ret = ret.select{|item| item!=""}
    ret = ret.collect{|i| if i =~ /\d+/ then i.to_i else i end}
  end
End

polish = PolishProcessor.new(STDIN.gets.chomp)
p polish.evaluate


