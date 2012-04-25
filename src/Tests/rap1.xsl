<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
	<html>
		<body>
			<xsl:apply-templates/>
		</body>
	</html>
</xsl:template>

<xsl:template match="rapport">
	<h2> Titre : <xsl:value-of select="titre"/></h2>
	<h3> Resumé : </h3> 
	<p> <xsl:value-of select="resume"/></p>
	<xsl:apply-templates/>
</xsl:template>

<xsl:template match="auteur">
	<h3>Auteur(s) :</h3> 
	<p><xsl:value-of select="prenom"/> <xsl:value-of select="nom"/></p>
</xsl:template>

<xsl:template match="chapitre">
	<h3>Chapitres</h3> 
	<h4><xsl:value-of select="titre"/></h4>
	<xsl:apply-templates/>
</xsl:template>

<xsl:template match="section">
	<h4>Section :</h4> 
	<h5><xsl:value-of select="titre"/></h5>
	<p><xsl:value-of select="p"/></p>
</xsl:template>

<xsl:template match="titre">
</xsl:template>

<xsl:template match="resume">
</xsl:template>

</xsl:stylesheet>