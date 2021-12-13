use std::fs;


fn main() {
    let mut column_amount: i32 =0;
    let mut row_amount: i32 = 1;
    let filename = "./../../Inputs/11.txt";
    let contents = fs::read_to_string(filename)
        .expect("Something went wrong reading the file");

    row_amount += contents.matches('\n').count() as i32;
    for a in contents.chars() {
        if a == '\n'  {
            break;
        }
        column_amount+=1;
    }
    let mut array = vec![vec![0u8; column_amount as usize]; row_amount as usize];
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
    let mut amount_of_flashes: i32 = 0;
    
    for _ in 0..100{
        for i in 0..row_amount{
            for k in 0..column_amount{
                array[i as usize][k as usize] += 1;
            }
        }
        for i in 0..row_amount{
            for k in 0..column_amount{
                if  array[i as usize][k as usize] == 10 {
                    array[i as usize][k as usize] = 0;
                    update_adiacent_cells(k,i, column_amount, row_amount, &mut array);
                }
            }
        }
        for a in 0..row_amount{
            for b in 0..column_amount{
                if array[a as usize][b as usize] == 0 {
                    amount_of_flashes+=1;
                }
            }
        }
        
    }
    println!("Result: {}", amount_of_flashes);
}

fn update_adiacent_cells(x: i32, y: i32, column_amount: i32, row_amount: i32, array: &mut std::vec::Vec<std::vec::Vec<u8>>){    
    for o in -1..2 as i32{
        for p  in -1..2 as i32{
            if p == 0 && o == 0{
                continue;
            }
            if array.get((y + o) as usize).map(|row| row.get((x + p) as usize)).flatten() == None{
                continue;
            }
            if array[(y + o) as usize][(x + p) as usize] == 0{
                continue;
            }
            if array[(y + o) as usize][(x + p) as usize] == 10{
                continue;
            }
            array[(y + o) as usize][(x + p) as usize] += 1;
            if array[(y + o) as usize][(x + p) as usize] == 10 {
                array[(y + o) as usize][(x + p) as usize] = 0;
                update_adiacent_cells(x + p, y + o, column_amount, row_amount, array);
            }
        }
    }
}

