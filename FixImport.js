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
    const airport_raw = await fetch(`https://raw.githubusercontent.com/lancard/korea-flight-database/refs/heads/master/database/airport.json`);
    const airport = await airport_raw.json();
    const runway_raw = await fetch(`https://raw.githubusercontent.com/lancard/korea-flight-database/refs/heads/master/database/runway.json`);
    const runway = await runway_raw.json();


    const boundary_navaids = mapped_navaids.filter(navaid => boundary_fix_names.includes(navaid.name));
    // map to convert lat and lon to decimal

    // print fir boundary fix list
    console.log(
`const char *fix_list[] = {
${boundary_navaids.map(navaid => `"FIR_BOUNDARY:${navaid.name}:${navaid.latitude}:${navaid.longitude}",`).join("\n")}
${mapped_navaids.map(navaid => `"FIX:${navaid.name}:${navaid.latitude}:${navaid.longitude}",`).join("\n")}
${Object.values(airport).map(a => `"AIRPORT:${a.icaoCode}:${a.latitude}:${a.longitude}",`).join("\n")}
${runway.map(navaid => `"RUNWAY:${navaid.airport}-${navaid.runway}:${navaid.startLatitude}:${navaid.startLongitude}",`).join("\n")}
${runway.map(navaid => `"RUNWAY:${navaid.airport}-${navaid.oppositeRunway}:${navaid.endLatitude}:${navaid.endLongitude}",`).join("\n")}
""};`);
}

generate();