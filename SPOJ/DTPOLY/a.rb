#!/bin/ruby
require 'rational'
#t = [:a, :b, :c, :d, :e, :f, :g, :h]

$mem = Hash.new()

def poly_devide(n,k)
        #p n.to_s + " " + k.to_s
        if(k ==0) then
                return 1
        end

        if(n == 3 || k > n-3) then
                return 0
        end

        if(k == n-3) then
                return catalan(n-2)
        end

        if(k == 1) then
                return n*(n-3) / 2
        end

        if $mem.include?([n,k]) then
                return $mem[[n,k]]
        end

        full_count = 0;
        for i in 3..(n+2)/2
                part = 0;
                # p "This part is for devide into "+i.to_s+" and "+(n+2-i).to_s
                for j in 0..k-1
                        devidep= poly_devide(i, j) * poly_devide(n+2-i, k-j-1)
                #       p "devide patterns="+devidep.to_s
                        part += devidep
                end
                #p "part="+ part.to_s + "way="+way_of_split(n,i).to_s

                full_count += way_of_split(n,i) * part
                #p "res="+res.to_s
        end
        #p "return="+(res/fact(k)).to_s
        res = full_count / fact(k)
        $mem.store([n,k], res);
        return res
end

def catalan(n)
        p=1
        j = 1
        while  j<n
                p = ((4*j+2)*p)/(j+2)
                j += 1
        end
        return p
end

def catalan2(n)
        if n==0 then
                return 1
        end
        return (2*(2*n-1)*catalan(n-1))/(n+1)
end

def catalan3(n)
        return fact(2*n) / (fact(n+1) * fact(n))
end

def fact(n)
        p=1
        while n>1
                p *= n
                n -= 1
        end
        return p
end

def way_of_split(n,k)
        if k<3 then
                p "error! 3"
        end
        if k>(n+2)/2 then
                p "error!"
        end

        if n%2 == 0 then
                if k == (n+2)/2 then
                        return n/2;
                end
                return n
        else
                return n
        end
end

#STDIN.gets
while line = STDIN.gets
        if(/exit/ =~ line)
                break;
        end
        nums = line.split(" ");
        if nums.length>1 then
                p poly_devide(nums[0].to_i, nums[1].to_i-1);
                #p catalan(100000)
        end
end
