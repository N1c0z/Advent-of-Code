use std::fs;

fn main() {
    let mut column_amount: i32 =0;
    let mut row_amount: i32 = 1;
    
    let filename = "./../../Inputs/09.txt";
    let contents = fs::read_to_string(filename)
        .expect("Something went wrong reading the file");

    row_amount += contents.matches('\n').count() as i32;

    for a in contents.chars() {
        if a == '\n'  {
            break;
        }
        column_amount+=1;
    }
    let mut array = vec![vec![0; column_amount as usize]; row_amount as usize];
    let mut current_column: i32 = 0;
    let mut current_row: i32 = 0;

    for a in contents.chars() {
        if a != '\n' && a != '\0' {
            array[current_row as usize][current_column as usize] = a as u8 - '0' as u8;
            current_column+=1;
        }else{
            current_column=0;
            current_row += 1;
        }
    }    
    let mut stuff: bool = true;
    let mut sum_stuff: i32 = 0;
    for i in 0..row_amount {
        for k in 0..column_amount {
            for o in -1..2 as i32{
                for p  in -1..2 as i32{
                    if ! ((o != 0) ^ (p != 0)){
                        continue;
                    }
                    if array.get((i + o) as usize).map(|row| row.get((k + p) as usize)).flatten() == None{
                        continue;
                    }
                    if array[(i + o) as usize][(k + p) as usize] <=  array[i as usize][k as usize]{
                        stuff = false;
                    }
                }
            }
            if stuff{
                sum_stuff += array[i as usize][k as usize] as i32 +1;
            }   
            stuff = true;
        }
    }
    println!("Sum: {}", sum_stuff);
}