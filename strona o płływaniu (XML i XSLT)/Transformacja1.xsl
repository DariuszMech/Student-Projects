<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" >

	<xsl:template match="/">
		<html>
			<head>
			
				<link type="text/css" href="style.css" rel="stylesheet"/>
			</head>
			<body>
				<header>Najlepsi Pływacy</header>
				<section>
						<xsl:apply-templates select="Najlepsi_plywacy/zawodnik1"/>
						<xsl:apply-templates select="Najlepsi_plywacy/zawodnik2"/>
						<xsl:apply-templates select="Najlepsi_plywacy/zawodnik3"/>
						<xsl:apply-templates select="Najlepsi_plywacy/zawodnik4"/>
						<xsl:apply-templates select="Najlepsi_plywacy/zawodnik5"/>
						<xsl:apply-templates select="Najlepsi_plywacy/zawodnik6"/>
						<xsl:apply-templates select="Najlepsi_plywacy/zawodnik7"/>
						<xsl:apply-templates select="Najlepsi_plywacy/zawodnik8"/>
						<xsl:call-template name="Koniec"/>
						
				</section>
				<footer>Najlepsi Pływacy - Dariusz Mech</footer>
			</body>
		</html>
	</xsl:template>

<xsl:template match="zawodnik1">
		<div class="zawodnik">
							<div class="imie">
								<xsl:value-of select="@imie"/>
								<xsl:value-of select="@spacja"/>
								<xsl:value-of select="@nazwisko"/>
							</div>
							<div class="info">
								<table class="ogolne">
									<tr>
										<th>Główny Styl</th>
										<th>Typ</th>
										<th>Narodowość</th>
										<th>Wzrost</th>					
									</tr>
									<tr>
										<td><xsl:value-of select="glowny_styl"/></td>
										<td><xsl:value-of select="typ"/></td>
										<td><xsl:value-of select="Narodowosc"/><xsl:if test="Narodowosc='USA'">*</xsl:if></td>
										<td>
												<xsl:choose>
													<xsl:when  test="wzrost &lt;= 3 or wzrost &gt;= 200">
														<font color="red">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:when test="wzrost &lt; 199 and wzrost &gt;= 185">
														<font color="green">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:otherwise>
														<font color="lightblue">
															<xsl:value-of select="format-number(wzrost, '###.##')"/>
														</font>
													</xsl:otherwise>
												</xsl:choose><xsl:value-of select="wzrost/@miara"/>
										</td>
									</tr>
								</table>
							</div>
							<div class="zdjecie">
								<img src="{zdjecie}" />
							</div>
							<div class="rekordy">
								<div class="rek">Rekordy życiowe w poszczególnych stylach</div>
								<xsl:for-each select="rekordy_zyciowe/czasy">
									<div class="styl"><xsl:value-of select="@styl"/>
										<div class="cyfry">
											<div class="dlugosc"> basen krótki (25m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_krotki"/>
											</div>
										</div>
										<div class="cyfry">
											<div class="dlugosc">basen długi (50m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_dlugi"/>
											</div>
										</div>
									</div>
								</xsl:for-each>
							</div>
							<div class="dodatkowe">
								<div class="linki">
									<div class="LINK"><a href="{linki/wikipedia}" target="_blank"> OSIĄGNIĘCIA</a></div>
									<div class="LINK"><a href="{linki/facebook}" target="_blank"> FACEBOOK </a></div>
									<div class="LINK"><a href="{linki/instagram}" target="_blank"> INSTAGRAM </a></div>
								</div>	
							</div>
		</div>
	</xsl:template>

<xsl:template match="zawodnik2">
		<div class="zawodnik">
							<div class="imie">
								<xsl:value-of select="@imie"/>
								<xsl:value-of select="@spacja"/>
								<xsl:value-of select="@nazwisko"/>
							</div>
							<div class="info">
								<table class="ogolne">
									<tr>
										<th>Główny Styl</th>
										<th>Typ</th>
										<th>Narodowość</th>
										<th>Wzrost</th>					
									</tr>
									<tr>
										<td><xsl:value-of select="glowny_styl"/></td>
										<td><xsl:value-of select="typ"/></td>
										<td><xsl:value-of select="Narodowosc"/><xsl:if test="Narodowosc='USA'">*</xsl:if></td>
										<td>
												<xsl:choose>
													<xsl:when  test="wzrost &lt;= 150">
														<font color="red">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:when test="wzrost &lt; 199 and wzrost &gt;= 185">
														<font color="green">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:otherwise>
														<font color="lightblue">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:otherwise>
												</xsl:choose><xsl:value-of select="wzrost/@miara"/>
										</td>
									</tr>
								</table>
							</div>
							<div class="zdjecie">
								<img src="{zdjecie}" />
							</div>
							<div class="rekordy">
								<div class="rek">Rekordy życiowe w poszczególnych stylach</div>
								<xsl:for-each select="rekordy_zyciowe/czasy">
									<div class="styl"><xsl:value-of select="@styl"/>
										<div class="cyfry">
											<div class="dlugosc"> basen krótki (25m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_krotki"/>
											</div>
										</div>
										<div class="cyfry">
											<div class="dlugosc">basen długi (50m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_dlugi"/>
											</div>
										</div>
									</div>
								</xsl:for-each>
							</div>
							<div class="dodatkowe">
								<div class="linki">
									<div class="LINK"><a href="{linki/wikipedia}" target="_blank"> OSIĄGNIĘCIA</a></div>
									<div class="LINK"><a href="{linki/facebook}" target="_blank"> FACEBOOK </a></div>
									<div class="LINK"><a href="{linki/instagram}" target="_blank"> INSTAGRAM </a></div>
								</div>	
							</div>
		</div>
	</xsl:template>

<xsl:template match="zawodnik3">
		<div class="zawodnik">
							<div class="imie">
								<xsl:value-of select="@imie"/>
								<xsl:value-of select="@spacja"/>
								<xsl:value-of select="@nazwisko"/>
							</div>
							<div class="info">
								<table class="ogolne">
									<tr>
										<th>Główny Styl</th>
										<th>Typ</th>
										<th>Narodowość</th>
										<th>Wzrost</th>					
									</tr>
									<tr>
										<td><xsl:value-of select="glowny_styl"/></td>
										<td><xsl:value-of select="typ"/></td>
										<td><xsl:value-of select="Narodowosc"/><xsl:if test="Narodowosc='USA'">*</xsl:if></td>
										<td>
												<xsl:choose>
													<xsl:when  test="wzrost &lt;= 150">
														<font color="red">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:when test="wzrost &lt; 199 and wzrost &gt;= 185">
														<font color="green">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:otherwise>
														<font color="lightblue">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:otherwise>
												</xsl:choose><xsl:value-of select="wzrost/@miara"/>
										</td>
									</tr>
								</table>
							</div>
							<div class="zdjecie">
								<img src="{zdjecie}" />
							</div>
							<div class="rekordy">
								<div class="rek">Rekordy życiowe w poszczególnych stylach</div>
								<xsl:for-each select="rekordy_zyciowe/czasy">
									<div class="styl"><xsl:value-of select="@styl"/>
										<div class="cyfry">
											<div class="dlugosc"> basen krótki (25m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_krotki"/>
											</div>
										</div>
										<div class="cyfry">
											<div class="dlugosc">basen długi (50m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_dlugi"/>
											</div>
										</div>
									</div>
								</xsl:for-each>
							</div>
							<div class="dodatkowe">
								<div class="linki">
									<div class="LINK"><a href="{linki/wikipedia}" target="_blank"> OSIĄGNIĘCIA</a></div>
									<div class="LINK"><a href="{linki/facebook}" target="_blank"> FACEBOOK </a></div>
									<div class="LINK"><a href="{linki/instagram}" target="_blank"> INSTAGRAM </a></div>
								</div>	
							</div>
		</div>
	</xsl:template>

<xsl:template match="zawodnik4">
		<div class="zawodnik">
							<div class="imie">
								<xsl:value-of select="@imie"/>
								<xsl:value-of select="@spacja"/>
								<xsl:value-of select="@nazwisko"/>
							</div>
							<div class="info">
								<table class="ogolne">
									<tr>
										<th>Główny Styl</th>
										<th>Typ</th>
										<th>Narodowość</th>
										<th>Wzrost</th>					
									</tr>
									<tr>
										<td><xsl:value-of select="glowny_styl"/></td>
										<td><xsl:value-of select="typ"/></td>
										<td><xsl:value-of select="Narodowosc"/><xsl:if test="Narodowosc='USA'">*</xsl:if></td>
										<td>
												<xsl:choose>
													<xsl:when  test="wzrost &lt;= 150">
														<font color="red">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:when test="wzrost &lt; 199 and wzrost &gt;= 185">
														<font color="green">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:otherwise>
														<font color="lightblue">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:otherwise>
												</xsl:choose><xsl:value-of select="wzrost/@miara"/>
										</td>
									</tr>
								</table>
							</div>
							<div class="zdjecie">
								<img src="{zdjecie}" />
							</div>
							<div class="rekordy">
								<div class="rek">Rekordy życiowe w poszczególnych stylach</div>
								<xsl:for-each select="rekordy_zyciowe/czasy">
									<div class="styl"><xsl:value-of select="@styl"/>
										<div class="cyfry">
											<div class="dlugosc"> basen krótki (25m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_krotki"/>
											</div>
										</div>
										<div class="cyfry">
											<div class="dlugosc">basen długi (50m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_dlugi"/>
											</div>
										</div>
									</div>
								</xsl:for-each>
							</div>
							<div class="dodatkowe">
								<div class="linki">
									<div class="LINK"><a href="{linki/wikipedia}" target="_blank"> OSIĄGNIĘCIA</a></div>
									<div class="LINK"><a href="{linki/facebook}" target="_blank"> FACEBOOK </a></div>
									<div class="LINK"><a href="{linki/instagram}" target="_blank"> INSTAGRAM </a></div>
								</div>	
							</div>
		</div>
	</xsl:template>

<xsl:template match="zawodnik5">
		<div class="zawodnik">
							<div class="imie">
								<xsl:value-of select="@imie"/>
								<xsl:value-of select="@spacja"/>
								<xsl:value-of select="@nazwisko"/>
							</div>
							<div class="info">
								<table class="ogolne">
									<tr>
										<th>Główny Styl</th>
										<th>Typ</th>
										<th>Narodowość</th>
										<th>Wzrost</th>					
									</tr>
									<tr>
										<td><xsl:value-of select="glowny_styl"/></td>
										<td><xsl:value-of select="typ"/></td>
										<td><xsl:value-of select="Narodowosc"/><xsl:if test="Narodowosc='USA'">*</xsl:if></td>
										<td>
												<xsl:choose>
													<xsl:when  test="wzrost &lt;= 150">
														<font color="red">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:when test="wzrost &lt; 199 and wzrost &gt;= 185">
														<font color="green">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:otherwise>
														<font color="lightblue">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:otherwise>
												</xsl:choose><xsl:value-of select="wzrost/@miara"/>
										</td>
									</tr>
								</table>
							</div>
							<div class="zdjecie">
								<img src="{zdjecie}" />
							</div>
							<div class="rekordy">
								<div class="rek">Rekordy życiowe w poszczególnych stylach</div>
								<xsl:for-each select="rekordy_zyciowe/czasy">
									<div class="styl"><xsl:value-of select="@styl"/>
										<div class="cyfry">
											<div class="dlugosc"> basen krótki (25m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_krotki"/>
											</div>
										</div>
										<div class="cyfry">
											<div class="dlugosc">basen długi (50m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_dlugi"/>
											</div>
										</div>
									</div>
								</xsl:for-each>
							</div>
							<div class="dodatkowe">
								<div class="linki">
									<div class="LINK"><a href="{linki/wikipedia}" target="_blank"> OSIĄGNIĘCIA</a></div>
									<div class="LINK"><a href="{linki/facebook}" target="_blank"> FACEBOOK </a></div>
									<div class="LINK"><a href="{linki/instagram}" target="_blank"> INSTAGRAM </a></div>
								</div>	
							</div>
		</div>
	</xsl:template>

<xsl:template match="zawodnik6">
		<div class="zawodnik">
							<div class="imie">
								<xsl:value-of select="@imie"/>
								<xsl:value-of select="@spacja"/>
								<xsl:value-of select="@nazwisko"/>
							</div>
							<div class="info">
								<table class="ogolne">
									<tr>
										<th>Główny Styl</th>
										<th>Typ</th>
										<th>Narodowość</th>
										<th>Wzrost</th>					
									</tr>
									<tr>
										<td><xsl:value-of select="glowny_styl"/></td>
										<td><xsl:value-of select="typ"/></td>
										<td><xsl:value-of select="Narodowosc"/><xsl:if test="Narodowosc='USA'">*</xsl:if></td>
										<td>
												<xsl:choose>
													<xsl:when  test="wzrost &lt;= 150">
														<font color="red">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:when test="wzrost &lt; 199 and wzrost &gt;= 185">
														<font color="green">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:otherwise>
														<font color="lightblue">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:otherwise>
												</xsl:choose><xsl:value-of select="wzrost/@miara"/>
										</td>
									</tr>
								</table>
							</div>
							<div class="zdjecie">
								<img src="{zdjecie}" />
							</div>
							<div class="rekordy">
								<div class="rek">Rekordy życiowe w poszczególnych stylach</div>
								<xsl:for-each select="rekordy_zyciowe/czasy">
									<div class="styl"><xsl:value-of select="@styl"/>
										<div class="cyfry">
											<div class="dlugosc"> basen krótki (25m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_krotki"/>
											</div>
										</div>
										<div class="cyfry">
											<div class="dlugosc">basen długi (50m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_dlugi"/>
											</div>
										</div>
									</div>
								</xsl:for-each>
							</div>
							<div class="dodatkowe">
								<div class="linki">
									<div class="LINK"><a href="{linki/wikipedia}" target="_blank"> OSIĄGNIĘCIA</a></div>
									<div class="LINK"><a href="{linki/facebook}" target="_blank"> FACEBOOK </a></div>
									<div class="LINK"><a href="{linki/instagram}" target="_blank"> INSTAGRAM </a></div>
								</div>	
							</div>
		</div>
	</xsl:template>

<xsl:template match="zawodnik7">
		<div class="zawodnik">
							<div class="imie">
								<xsl:value-of select="@imie"/>
								<xsl:value-of select="@spacja"/>
								<xsl:value-of select="@nazwisko"/>
							</div>
							<div class="info">
								<table class="ogolne">
									<tr>
										<th>Główny Styl</th>
										<th>Typ</th>
										<th>Narodowość</th>
										<th>Wzrost</th>					
									</tr>
									<tr>
										<td><xsl:value-of select="glowny_styl"/></td>
										<td><xsl:value-of select="typ"/></td>
										<td><xsl:value-of select="Narodowosc"/><xsl:if test="Narodowosc='USA'">*</xsl:if></td>
										<td>
												<xsl:choose>
													<xsl:when  test="wzrost &lt;= 150">
														<font color="red">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:when test="wzrost &lt; 199 and wzrost &gt;= 185">
														<font color="green">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:otherwise>
														<font color="lightblue">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:otherwise>
												</xsl:choose><xsl:value-of select="wzrost/@miara"/>
										</td>
									</tr>
								</table>
							</div>
							<div class="zdjecie">
								<img src="{zdjecie}" />
							</div>
							<div class="rekordy">
								<div class="rek">Rekordy życiowe w poszczególnych stylach</div>
								<xsl:for-each select="rekordy_zyciowe/czasy">
									<div class="styl"><xsl:value-of select="@styl"/>
										<div class="cyfry">
											<div class="dlugosc"> basen krótki (25m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_krotki"/>
											</div>
										</div>
										<div class="cyfry">
											<div class="dlugosc">basen długi (50m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_dlugi"/>
											</div>
										</div>
									</div>
								</xsl:for-each>
							</div>
							<div class="dodatkowe">
								<div class="linki">
									<div class="LINK"><a href="{linki/wikipedia}" target="_blank"> OSIĄGNIĘCIA</a></div>
									<div class="LINK"><a href="{linki/facebook}" target="_blank"> FACEBOOK </a></div>
									<div class="LINK"><a href="{linki/instagram}" target="_blank"> INSTAGRAM </a></div>
								</div>	
							</div>
		</div>
	</xsl:template>	

<xsl:template match="zawodnik8">
		<div class="zawodnik">
							<div class="imie">
								<xsl:value-of select="@imie"/>
								<xsl:value-of select="@spacja"/>
								<xsl:value-of select="@nazwisko"/>
							</div>
							<div class="info">
								<table class="ogolne">
									<tr>
										<th>Główny Styl</th>
										<th>Typ</th>
										<th>Narodowość</th>
										<th>Wzrost</th>					
									</tr>
									<tr>
										<td><xsl:value-of select="glowny_styl"/></td>
										<td><xsl:value-of select="typ"/></td>
										<td><xsl:value-of select="Narodowosc"/><xsl:if test="Narodowosc='USA'">*</xsl:if></td>
										<td>
												<xsl:choose>
													<xsl:when  test="wzrost &lt;= 150">
														<font color="red">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:when test="wzrost &lt; 199 and wzrost &gt;= 185">
														<font color="green">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:when>
													<xsl:otherwise>
														<font color="lightblue">
															<xsl:value-of select="format-number(wzrost, '###,###')"/>
														</font>
													</xsl:otherwise>
												</xsl:choose><xsl:value-of select="wzrost/@miara"/>
										</td>
									</tr>
								</table>
							</div>
							<div class="zdjecie">
								<img src="{zdjecie}" />
							</div>
							<div class="rekordy">
								<div class="rek">Rekordy życiowe w poszczególnych stylach</div>
								<xsl:for-each select="rekordy_zyciowe/czasy">
									<div class="styl"><xsl:value-of select="@styl"/>
										<div class="cyfry">
											<div class="dlugosc"> basen krótki (25m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_krotki"/>
											</div>
										</div>
										<div class="cyfry">
											<div class="dlugosc">basen długi (50m)</div>
											<div class="wszystkie">
												<div class="wynik">50m</div>
												<div class="wynik">100m</div>
												<div class="wynik">200m</div>
												<div class="wynik">400m</div>
											</div>
											<div class="czasy">
												<xsl:value-of select="basen_dlugi"/>
											</div>
										</div>
									</div>
								</xsl:for-each>
							</div>
							<div class="dodatkowe">
								<div class="linki">
									<div class="LINK"><a href="{linki/wikipedia}" target="_blank"> OSIĄGNIĘCIA</a></div>
									<div class="LINK"><a href="{linki/facebook}" target="_blank"> FACEBOOK </a></div>
									<div class="LINK"><a href="{linki/instagram}" target="_blank"> INSTAGRAM </a></div>
								</div>	
							</div>
		</div>
	</xsl:template>
	
<xsl:template name="Koniec">
	Koniec
</xsl:template>

</xsl:stylesheet>