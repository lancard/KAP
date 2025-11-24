const boundary_fix_names = ["AGAVO", "LAMEN", "ANDOL", "APELA", "ATOTI", "BESNA", "IGRAS", "INVOK", "KALEK", "KANSU", "LANAT", "MESOV", "MUGUS", "ONIKU", "RUGMA", "SAMDO", "SAPRA", "BEDAR", "GOLOT", "TOMUK", "VASRO", "ADNUR", "RIVAT"];

async function generate() {
    const navaid_raw = await fetch(`https://raw.githubusercontent.com/lancard/korea-flight-database/refs/heads/master/database/navaid.json`);
    const navaid = await navaid_raw.json();
    const mapped_navaids = navaid.map(navaid => {
        return {
            name: navaid.name,
            navaidType: navaid.navaidType,
            latitude: navaid.latitude,
            longitude: navaid.longitude
        };
    });

    const boundary_navaids = mapped_navaids.filter(navaid => boundary_fix_names.includes(navaid.name));
    // map to convert lat and lon to decimal

    // print fir boundary fix list
    console.log(
        `
unordered_map<std::string, CPosition> fir_boundary_fix_map;
unordered_map<std::string, CPosition> fix_map;

CPosition GetCPositionFromString(const string& latitude, const string& longitude) {
    CPosition pos;
    pos.LoadFromStrings(longitude.c_str(), latitude.c_str());
    return pos;
}

void InitializeFirBoundaryFixes() {
${boundary_navaids.map(navaid => `    fir_boundary_fix_map["${navaid.name}"] = GetCPositionFromString("${navaid.latitude}", "${navaid.longitude}");`).join("\n")}
}    

void InitializeFixes() {
${mapped_navaids.map(navaid => `    fix_map["${navaid.name}"] = GetCPositionFromString("${navaid.latitude}", "${navaid.longitude}");`).join("\n")}
}
`
    );    
}

generate();